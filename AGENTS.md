# Assistant workflow

The user wants to spend time on power-electronics theory and practical work. Maintain the documentation yourself; do not ask the user to populate templates or tables.

## After a session

1. Extract circuit changes, operating conditions, evidence, observations, and questions from the conversation and attachments.
2. Update the active project's README with its current state and one concrete next action.
3. Create or update the relevant experiment record. Reference actual evidence files.
4. Preserve raw evidence and earlier results. Mark revised interpretations with a date and reason.
5. Keep open questions in the project notes. Add an explanation when supported by evidence.

## Accuracy

- Distinguish user-reported information, verified facts, predictions, simulated results, and measured results.
- Never invent component values, pin connections, measurements, dates of bench work, or completed tasks.
- Mark unknowns as unverified. Ask only for information needed for the next engineering step.
- Inspect the actual switching topology and gate-drive reference before modeling the existing circuit. A list of components does not establish the topology.
- Use manufacturer documentation for device behavior, pinouts, and model compatibility. Record the source, model version, and download date when obtaining models.
- Label simplified models and their limits. Do not call a generic simulation an exact replica of the bench circuit.
- Before recommending probe connections, establish the instrument's ground connections and the relevant circuit node references.
- Do not redistribute third-party references or models without checking their terms.

## Keep it small

Use Markdown for notes. Prefer one useful experiment record over many empty documents. Do not create dashboards, automation, or elaborate tracking systems unless requested. Do not change or publish a repository outside the user's authorized scope.
