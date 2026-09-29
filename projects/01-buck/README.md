# 01 — Open-loop buck converter

## Goal

Recreate the existing bench circuit in LTspice, understand its waveforms, and compare simulated results with oscilloscope measurements under matching conditions.

## Current state

The user has described the bench components and shared 12 V supply. The first experiment now records the reported setup and unresolved transcription details. No LTspice model has been created or tested here.

## Next action

Confirm the PWM code, inductor value/unit, driver marking, and switching-node wiring. The assistant maintains the documentation from this evidence.

## First experiment

[EXP-001 — Recreate the baseline circuit](experiments/EXP-001-baseline.md).

## Files

- `simulation/`: LTspice source files, selected exports, and model provenance.
- `hardware/`: circuit photos, wiring sketches, and build changes.
- `experiments/`: settings, evidence, comparisons, and conclusions for each experiment.
- [Notes](notes.md): questions and learning progress.

## Working sequence

Confirm the circuit → establish a baseline simulation → include real component behavior → compare with bench evidence → investigate one difference at a time.

Simulation scope and settings will be chosen after the existing circuit is documented. Closed-loop control remains a later project.
