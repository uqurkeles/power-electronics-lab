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
