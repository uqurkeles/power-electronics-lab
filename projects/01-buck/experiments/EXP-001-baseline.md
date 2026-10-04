# EXP-001 — Recreate the baseline circuit

Status: reconstructing the user-reported circuit. No measurements or simulation results recorded.

## Engineering question

Can an LTspice model reproduce the main behavior of the existing bench circuit at one fixed operating point?

## Setup

## Reported setup — 2026-09-29

Transcribed from the user's description; these are reported details, not measured or photographically verified values.

| Item | Reported detail | Verification |
| --- | --- | --- |
| Adapter | 12 V, 1 A | User-reported rating |
| Power route | Adapter into Arduino DC barrel jack; Arduino VIN used to feed breadboard | Inferred from transcription; board model and wiring pending |
| USB | Arduino also connected to computer by USB | User-reported; connection and grounding pending |
| Build | Solderless breadboard | User-reported |
| Gate driver | 12 V supply; likely TC4426 | Spoken name transcribed as TC-4626; exact marking pending |
| MOSFET | IRF9540 | User-reported; manufacturer, suffix, and connections pending |
| Diode | 1N5819 | User-reported; orientation pending |
| Inductor | Possibly 470 uH | Value and unit unclear in transcription |
| Capacitor | 470 uF | User-reported; voltage rating and ESR unknown |
| Load | 22 ohm, likely 5 W | Inferred from spoken 22R and five; rating pending |
| PWM | Arduino; possibly 50 kHz and 60% duty | Transcription ambiguous; code needed |

The same nominal 12 V rail supplies both the power stage and driver. Actual VIN/breadboard voltage has not been measured here. No output measurement supplied.

## Conditional topology interpretation

IRF9540 is a P-channel MOSFET. A conventional high-side implementation would have its source on the input rail and drain at the switch node. With source at 12 V, a gate near 12 V gives VGS near 0 V (off); a gate near 0 V gives VGS near -12 V (on). This explains the shared rail arrangement if the wiring matches. It is not confirmation of the user's actual wiring.

If the driver is TC4426, it is inverting. Combined with a high-side P-channel MOSFET, Arduino input HIGH would command MOSFET on; the driver's output-high duty is not the MOSFET on-duty. Verify the actual part and connections before using this interpretation.

Sources checked 2026-09-29:
- Vishay IRF9540 datasheet: https://www.vishay.com/docs/91078/91078.pdf (P-channel; VGS maximum +/-20 V).
- Microchip selector guide: https://ww1.microchip.com/downloads/en/DeviceDoc/21060s.pdf (TC4426 driver selection reference).
- Microchip device page: https://www.microchip.com/en-us/product/tc4426 .

## Next action

Obtain Arduino PWM code, confirm inductor value/unit and driver marking, and obtain a circuit photo or wiring sketch establishing MOSFET source/drain, driver reference, and diode orientation. Then create the LTspice baseline.


Probe points, channel references, attenuation, coupling, and acquisition settings: to be documented before bench comparison.

## Plan

1. Reconstruct the actual circuit from photos, markings, and wiring information.
2. Select and document the initial modeling assumptions.
3. Run a transient simulation and inspect startup and steady-state behavior.
4. Record selected waveforms under the same bench operating conditions.
5. Compare relevant quantities over documented steady-state windows.
6. Select one discrepancy to investigate in the next experiment.

## Evidence

No files supplied yet. Store the circuit source, trace exports, captures, and photos used for this comparison, and link them here.

## Results and interpretation

Pending. Keep calculated predictions, simulation results, and bench measurements separate. Record differences with units and the comparison reference. Do not treat agreement alone as proof that every part of the model is correct.

## Next action

Confirm uncertain values and obtain PWM code and circuit wiring.

## Confirmed by user and supplied code — 2026-10-04

This update supersedes the uncertain transcription above; earlier notes remain for provenance.

- Driver: TC4426, confirmed by user.
- Inductor: 470 uH, confirmed by user.
- Output capacitor: 470 uF, confirmed by user.
- Load: 22 ohm, 5 W, confirmed by user.
- Arduino code supplied and preserved unchanged in [buck_pwm_20khz](../firmware/buck_pwm_20khz/buck_pwm_20khz.ino).
- Code configures D9/OC1A, Timer1 Fast PWM mode 14, ICR1=799, OCR1A=400, and prescaler 1.
- Assuming the classic 16 MHz AVR UNO/Nano indicated in the sketch: nominal frequency = 16,000,000 / (799+1) = 20,000 Hz, period = 50 us, duty approximately 50%. This is code-derived, not scope-verified. The board variant/clock should be confirmed if it is not a classic AVR board.
- The earlier tentative 50 kHz / 60% setting is superseded. Preserve the original sketch; do not silently change OCR1A for a tiny timer-count difference.

## Baseline predictions, not measurements

For a conventional buck at nominal 12 V input and 50% switch-on duty in continuous conduction with ideal components:

- Output voltage approximately 6 V.
- Load current approximately 6/22 = 0.273 A.
- Load power approximately 6^2/22 = 1.64 W.
- Inductor peak-to-peak ripple approximately (12-6)*25 us/470 uH = 0.319 A; ideal minimum current approximately 0.113 A, consistent with continuous conduction at this operating point.

Actual input at Arduino VIN may differ from adapter rating; real diode, MOSFET, winding, and supply losses are not included in these predictions.

## Remaining step before model creation

Confirm that IRF9540 source connects to VIN, drain to the switch node/inductor, diode cathode (stripe) to the switch node and anode to ground, output capacitor/load from the far end of the inductor to ground, driver output to gate, and all logic/driver references to common ground. Gate resistor/pull-up and driver decoupling values remain unspecified. No exact schematic or simulation has been produced yet.

TC4426 inversion verified against Microchip DS20001422G (Functional Block Diagram), accessed 2026-10-04: https://ww1.microchip.com/downloads/en/DeviceDoc/20001422G.pdf . With the conditional high-side P-channel wiring, Arduino HIGH leads to driver LOW and MOSFET on; Arduino LOW leads to driver HIGH and MOSFET off.
