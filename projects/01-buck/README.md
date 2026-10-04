# 01 — Open-loop buck converter

## Goal

Recreate the existing bench circuit in LTspice, understand its waveforms, and compare simulated results with oscilloscope measurements under matching conditions.

## Current state

The user confirmed TC4426, 470 uH, 470 uF, and a 22 ohm / 5 W load. The supplied Arduino sketch configures nominal 20 kHz PWM at approximately 50% duty on D9 for a classic 16 MHz AVR board. The shared supply is nominally 12 V. No LTspice model has been created or tested here.

## Next action

Confirm the source/drain, diode orientation, gate connection, and common-ground wiring; then create the LTspice baseline. The assistant maintains the documentation from this evidence.

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

Simulation scope and settings will be chosen after the existing circuit is documented. Closed-loop control remains a later project.
