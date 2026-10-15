# Power Electronics Lab

A practical learning workspace: understand a circuit, simulate it, measure it, and explain the differences.

## Start here

Current project: [01 — Open-loop buck converter](projects/01-buck/README.md).

Next action: share a photo of the existing circuit and component markings. Add whatever operating settings are known in the conversation. The assistant records the details and identifies what still needs checking.

## Working together

Ugi builds, simulates, measures, and asks questions. The assistant maintains the project notes, experiment records, questions, and next steps from those conversations. No forms need to be completed before working.

Evidence belongs beside the experiment that produced it. A screenshot alone is useful, but its circuit version, settings, probe points, and date make it reusable.

## Contents

- `projects/01-buck/`: existing buck circuit, simulations, hardware evidence, and experiments.
- `projects/02-boost/`: initial boost bench/simulation comparison and open questions.
- `references/`: source links and references used in the projects.
- `AGENTS.md`: instructions for assistants maintaining this workspace.

## Current learning step (2026-10-16)

Initial buck and boost practical passes have been carried out. The boost result is recorded in [EXP-002](projects/02-boost/experiments/EXP-002-boost-comparison.md): qualitative comparison and an approximate 20 V output ceiling as duty was changed; cause still unverified. Inductor/load sweeps are intentionally deferred.

**Next action:** continue the course lesson following the boost experiment; write one prediction, compare theory/LTspice with a waveform or output measurement, record one conclusion, and proceed. Do not treat preliminary comparisons as full validation.

## Repository

This workspace is maintained at https://github.com/uqurkeles/power-electronics-lab.

Share circuit evidence and questions in the conversation; the assistant updates this repository within the requested scope. Unknowns stay explicitly marked until confirmed.

Only upload books, course material, and third-party models when redistribution is permitted. Otherwise record a source link. Large LTspice output files are excluded by default; export the relevant traces and retain selected evidence.
