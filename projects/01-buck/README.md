# 01 — Open-loop buck converter

## Goal

Recreate the existing bench circuit in LTspice, understand its waveforms, and compare simulated results with oscilloscope measurements under matching conditions.

## Current state

- User reports an existing working circuit using a TC4426, MOSFET, diode, inductor, capacitor, and load.
- Exact part numbers, values, wiring, input supply, PWM settings, and measured output have not yet been verified for this workspace.
- No LTspice model has been created or tested here.

## Next action

Obtain a photo of the circuit and component markings, plus any known supply and PWM settings. The assistant will document the circuit and ask for any missing detail needed to simulate it.

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
