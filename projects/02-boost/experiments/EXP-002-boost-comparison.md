# EXP-002 — Boost converter: simulation vs bench (2026-10-15/16)

## Aim
Understand the basic switching waveforms of an open-loop boost converter, compare LTspice with hardware, and identify questions to revisit when theory advances.

## User-reported work and observations
- Physical boost circuit was assembled and operated.
- Switching waveforms were observed on the oscilloscope and qualitatively compared with LTspice.
- Changing duty cycle did not raise observed output voltage above approximately **20 V** in this setup.
- The user suspects a power-budget/supply constraint. This is a **hypothesis**, not a verified diagnosis.
- Inductor-value and load-resistance sweeps were **not** examined in detail.

## Evidence and operating conditions
- Date: user report on 2026-10-16, referring to previous session.
- Confirmed recorded observation: approximate output ceiling 20 V.
- Exact boost topology, schematic, measured input voltage/current, switch type, diode, actual load, inductor value, duty-frequency settings, waveform screenshots and raw LTspice files: **not yet archived/verified for this experiment**.
- Previous buck hardware used 12 V nominal supply, 470 µH and 22 Ω; **do not automatically carry these over to boost**.

## Engineering interpretation / open questions
1. Boost voltage conversion depends on duty ratio in ideal CCM, but the formula alone does not establish the actual operating point.
2. At the plateau, determine input voltage and current, supply current-limit indicator, input and output power, and load resistance.
3. Check MOSFET gate drive, switch-node shape, diode behavior, inductor saturation, thermal losses, and CCM/DCM.
4. Only after matching operating conditions, quantify simulation/bench differences.
5. Return later for one-variable-at-a-time load/inductance/duty sweeps and ripple evaluation.

## Learning decision
This preliminary converter exercise is **complete at introductory depth**; it is not certified as an optimized or fully diagnosed power design. Avoid analysis loops now; revisit the flagged questions after additional Coursera converter theory.

## Next action
Continue the **next actual Coursera lesson following the completed boost exercise**. Take one new mechanism or relation from the lesson, predict its waveform/output, demonstrate in LTspice and, if practical and safe, on a low-power real circuit; archive one comparison and move on.
