local autocmd = vim.api.nvim_create_autocmd
local augroup = vim.api.nvim_create_augroup

local group = augroup("tree-sitter-bi", { clear = true })

-- Set `bi` as the filetype for `.bi` files
autocmd({ "BufRead", "BufNewFile" }, {
  group = group,
  command = "set filetype=bi",
  pattern = "*.bi",
})

local parsers = require "nvim-treesitter.parsers"
---@type table<string, ParserInfo>
local parser_configs = parsers.get_parser_configs()

parser_configs.bi = {
  install_info = {
    url = vim.fn.expand "<sfile>:h:h",
    branch = "main",
    files = { "src/parser.c", "src/scanner.c" },
  },
  filetype = "bi",
  maintainers = { "@ej-shafran" },
}
