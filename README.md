# tree-sitter-bi

A TreeSitter parser for the [BI
format](https://github.com/tsoding/bi-format).

Read more about [custom TreeSitter
parsers](https://tree-sitter.github.io/tree-sitter/creating-parsers).

![Screenshot](https://github.com/ej-shafran/tree-sitter-bi/assets/116496520/7f5de633-ddb4-4b73-a94e-7a6aca229091)

## Running Locally

Make sure you install all the dependencies. I use PNPM but you can use
NPM (just swap `pnpm` command with `npm`).

```bash
pnpm install
```

Build the external scanner (needs C compiler):

```bash
pnpm run build
```

To see it in full effect, use `pnpm highlight` (if your terminal has
colors, otherwise either just parse regularly or use the `--html` flag
to create HTML):

```bash
pnpm run highlight examples/bi.bi
```

If you make any changes to `grammar.js`, make sure to run:

```bash
pnpm run generate
```

To update the relevant files in the `src/` directory.

Finally, you can run the tests in the `test/corpus/` directory:

```bash
pnpm test
```

## TODOs

- [ ] Make this usable directly as a Neovim plugin
