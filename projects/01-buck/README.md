# 01 — Open-loop buck converter

## Goal

Recreate the existing bench circuit in LTspice, understand its waveforms, and compare simulated results with oscilloscope measurements under matching conditions.

## Current state

The user confirmed TC4426, 470 uH, 470 uF, and a 22 ohm / 5 W load. The supplied Arduino sketch configures nominal 20 kHz PWM at approximately 50% duty on D9 for a classic 16 MHz AVR board. The shared supply is nominally 12 V.

A first LTspice schematic and waveform screenshot has been supplied. It uses a temporary IRF7343P model, 47 uH, and 5 ohm; these differ from the hardware. Its output staying near 11.43 V strongly suggests reversed MOSFET source/drain and body-diode conduction, pending the user's .asc/netlist. See [first draft review](experiments/2026-10-05-first-ltspice-review.md).

## Next action

Verify and correct the P-channel source/drain connections, set L=470u and load=22, then rerun and inspect output, switch node, gate-to-source voltage, and inductor current. Supply the .asc file to verify the exact wiring. The assistant maintains the documentation from this evidence.

## First experiment

[EXP-001 — Recreate the baseline circuit](experiments/EXP-001-baseline.md).

## Files

- `firmware/`: original Arduino PWM sketch supplied by the user.
- `simulation/`: LTspice source files, selected exports, and model provenance.
- `hardware/`: circuit photos, wiring sketches, and build changes.
- `experiments/`: settings, evidence, comparisons, and conclusions for each experiment.
- [Notes](notes.md): questions and learning progress.

## Working sequence

Confirm the circuit → establish a baseline simulation → include real component behavior → compare with bench evidence → investigate one difference at a time.

Closed-loop control remains a later project.
