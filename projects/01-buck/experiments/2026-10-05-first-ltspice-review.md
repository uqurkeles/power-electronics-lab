# First LTspice draft review — 2026-10-05

## Evidence inspected

- User-supplied course archive: `_978686b0cc9733c759557acce5c161bd_Buck (2).zip`; inspected buck.asc, switching.lib, and the included driver/PWM source files.
- User-supplied screenshot: `image(1).png`, LTspice Draft2 schematic and plots. The user's .asc/netlist was not supplied; screenshot interpretations require confirmation.
- Course files have not been copied into this public repository because redistribution terms are unknown.

## Course versus user's draft

| Item | Course archive | User screenshot | Reported bench target |
| --- | --- | --- | --- |
| Input | 24 V | 12 V | nominal 12 V adapter |
| MOSFET | IRFS4010 N-channel | IRF7343P model | IRF9540 P-channel |
| Gate drive | Generic floating driver, 12 V relative to MOSFET source | Ground-referenced ideal 0–12 V PULSE directly at gate | TC4426 powered from common nominal 12 V rail |
| PWM | 100 kHz, duty command 0.4, VM=1, Voffset=0 | 25 us pulse / 50 us period; approximately 50%, 20 kHz | Arduino Timer1 20 kHz, approximately 50% |
| Inductor | 40 uH plus explicit 0.1 ohm winding resistance | 47 uH | 470 uH |
| Capacitor | 22 uF | 470 uF | 470 uF |
| Load | 5 ohm | 5 ohm | 22 ohm, 5 W |
| Diode | RF1601NS2D | 1N5819 | 1N5819 |

## Observations

- Red output trace stays around 11.43 V. Blue presumed switch-node trace stays near input (roughly 11.1–11.9 V) rather than alternating near input and ground/freewheel level. Green presumed gate trace spans 0–12 V.
- This behavior strongly suggests reversed P-channel source/drain and forward conduction through its intrinsic body diode while nominally off. The rotated symbol appears consistent with that interpretation; actual netlist needed for verification.
- For the conventional P-channel high-side buck, source must connect to VIN and drain to SW. The body diode anode is at drain/SW and cathode at source/VIN, so it blocks direct VIN-to-SW supply when the channel is off.
- For a 12 V source node, gate=12 V means VGS=0 V/off and gate=0 V means VGS=-12 V/on.
- The screenshot's 0–12 V gate pulse stands in for the driver OUTPUT. It is not the Arduino's 0–5 V output and does not model TC4426 delay/output resistance.
- IRF7343P is a temporary P-channel substitute, not an IRF9540 model; loss and switching details cannot be compared as an exact hardware model.

## Next action

1. Inspect M1 source/drain using the symbol pins or generated netlist and correct to source=VIN, drain=SW.
2. Set L1=470u and R1=22 to match the user's hardware.
3. Label nodes VIN, SW, GATE, OUT.
4. Use a controlled transient setup such as `.tran 0 50m 0 200n startup` for a first startup/steady-state check. This is a suggested simulation setting, not an executed result.
5. Plot V(OUT), V(SW), V(GATE,VIN), and I(L1). Zoom to a few switching cycles near the end.
6. Supply Draft2.asc or its netlist to confirm wiring. Then refine the MOSFET model and driver representation.

No corrected model has been executed in this workspace, and no bench waveforms have been supplied.

## Manufacturer reference

Infineon IRF7343 datasheet (N/P device and intrinsic diode information): https://www.infineon.com/assets/row/public/documents/24/49/infineon-irf7343-datasheet-en.pdf . Accessed 2026-10-05. IRF7343P naming in the screenshot denotes the P-channel model selected in LTspice; it does not establish the bench device.
