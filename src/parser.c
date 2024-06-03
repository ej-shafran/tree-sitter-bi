#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 20
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 15
#define ALIAS_COUNT 0
#define TOKEN_COUNT 8
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  anon_sym_COLONi = 1,
  anon_sym_SPACE = 2,
  anon_sym_LF = 3,
  aux_sym_int_value_token1 = 4,
  anon_sym_COLONb = 5,
  aux_sym_blob_value_token1 = 6,
  sym_identifier = 7,
  sym_document = 8,
  sym_int_field = 9,
  sym_int_value = 10,
  sym_blob_field = 11,
  sym_blob_value = 12,
  sym_length = 13,
  aux_sym_document_repeat1 = 14,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_COLONi] = "field_marker",
  [anon_sym_SPACE] = " ",
  [anon_sym_LF] = "\n",
  [aux_sym_int_value_token1] = "int_value_token1",
  [anon_sym_COLONb] = "field_marker",
  [aux_sym_blob_value_token1] = "blob_value_token1",
  [sym_identifier] = "identifier",
  [sym_document] = "document",
  [sym_int_field] = "int_field",
  [sym_int_value] = "int_value",
  [sym_blob_field] = "blob_field",
  [sym_blob_value] = "blob_value",
  [sym_length] = "length",
  [aux_sym_document_repeat1] = "document_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_COLONi] = anon_sym_COLONi,
  [anon_sym_SPACE] = anon_sym_SPACE,
  [anon_sym_LF] = anon_sym_LF,
  [aux_sym_int_value_token1] = aux_sym_int_value_token1,
  [anon_sym_COLONb] = anon_sym_COLONi,
  [aux_sym_blob_value_token1] = aux_sym_blob_value_token1,
  [sym_identifier] = sym_identifier,
  [sym_document] = sym_document,
  [sym_int_field] = sym_int_field,
  [sym_int_value] = sym_int_value,
  [sym_blob_field] = sym_blob_field,
  [sym_blob_value] = sym_blob_value,
  [sym_length] = sym_length,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_COLONi] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_SPACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_int_value_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_COLONb] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_blob_value_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_document] = {
    .visible = true,
    .named = true,
  },
  [sym_int_field] = {
    .visible = true,
    .named = true,
  },
  [sym_int_value] = {
    .visible = true,
    .named = true,
  },
  [sym_blob_field] = {
    .visible = true,
    .named = true,
  },
  [sym_blob_value] = {
    .visible = true,
    .named = true,
  },
  [sym_length] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_document_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(5);
      if (lookahead == '\n') ADVANCE(9);
      if (lookahead == '\r') SKIP(0);
      if (lookahead == ' ') ADVANCE(8);
      if (lookahead == ':') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(18);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(11);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(6);
      END_STATE();
    case 3:
      if (lookahead == 'b') ADVANCE(1);
      if (lookahead == 'i') ADVANCE(2);
      END_STATE();
    case 4:
      if (eof) ADVANCE(5);
      if (lookahead == '\r') ADVANCE(13);
      if (lookahead == ':') ADVANCE(16);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(17);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_COLONi);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_COLONi);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(17);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_SPACE);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_LF);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(aux_sym_int_value_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_COLONb);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_COLONb);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(17);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(aux_sym_blob_value_token1);
      if (lookahead == '\r') ADVANCE(13);
      if (lookahead == ':') ADVANCE(16);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(17);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(aux_sym_blob_value_token1);
      if (lookahead == ' ') ADVANCE(12);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(17);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(aux_sym_blob_value_token1);
      if (lookahead == ' ') ADVANCE(7);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(17);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(aux_sym_blob_value_token1);
      if (lookahead == 'b') ADVANCE(14);
      if (lookahead == 'i') ADVANCE(15);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(17);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(aux_sym_blob_value_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(17);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_identifier);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(18);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 4},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_COLONi] = ACTIONS(1),
    [anon_sym_SPACE] = ACTIONS(1),
    [anon_sym_LF] = ACTIONS(1),
    [aux_sym_int_value_token1] = ACTIONS(1),
    [anon_sym_COLONb] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(12),
    [sym_int_field] = STATE(2),
    [sym_blob_field] = STATE(2),
    [aux_sym_document_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_COLONi] = ACTIONS(5),
    [anon_sym_COLONb] = ACTIONS(7),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(5), 1,
      anon_sym_COLONi,
    ACTIONS(7), 1,
      anon_sym_COLONb,
    ACTIONS(9), 1,
      ts_builtin_sym_end,
    STATE(3), 3,
      sym_int_field,
      sym_blob_field,
      aux_sym_document_repeat1,
  [15] = 4,
    ACTIONS(11), 1,
      ts_builtin_sym_end,
    ACTIONS(13), 1,
      anon_sym_COLONi,
    ACTIONS(16), 1,
      anon_sym_COLONb,
    STATE(3), 3,
      sym_int_field,
      sym_blob_field,
      aux_sym_document_repeat1,
  [30] = 4,
    ACTIONS(19), 1,
      ts_builtin_sym_end,
    ACTIONS(23), 1,
      aux_sym_blob_value_token1,
    STATE(6), 1,
      sym_blob_value,
    ACTIONS(21), 2,
      anon_sym_COLONi,
      anon_sym_COLONb,
  [44] = 1,
    ACTIONS(25), 3,
      ts_builtin_sym_end,
      anon_sym_COLONi,
      anon_sym_COLONb,
  [50] = 1,
    ACTIONS(27), 3,
      ts_builtin_sym_end,
      anon_sym_COLONi,
      anon_sym_COLONb,
  [56] = 1,
    ACTIONS(29), 3,
      ts_builtin_sym_end,
      anon_sym_COLONi,
      anon_sym_COLONb,
  [62] = 2,
    ACTIONS(31), 1,
      aux_sym_int_value_token1,
    STATE(16), 1,
      sym_int_value,
  [69] = 2,
    ACTIONS(33), 1,
      aux_sym_int_value_token1,
    STATE(18), 1,
      sym_length,
  [76] = 1,
    ACTIONS(35), 1,
      sym_identifier,
  [80] = 1,
    ACTIONS(37), 1,
      sym_identifier,
  [84] = 1,
    ACTIONS(39), 1,
      ts_builtin_sym_end,
  [88] = 1,
    ACTIONS(41), 1,
      anon_sym_SPACE,
  [92] = 1,
    ACTIONS(43), 1,
      anon_sym_SPACE,
  [96] = 1,
    ACTIONS(45), 1,
      anon_sym_LF,
  [100] = 1,
    ACTIONS(47), 1,
      anon_sym_LF,
  [104] = 1,
    ACTIONS(49), 1,
      anon_sym_LF,
  [108] = 1,
    ACTIONS(51), 1,
      anon_sym_LF,
  [112] = 1,
    ACTIONS(53), 1,
      anon_sym_LF,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 15,
  [SMALL_STATE(4)] = 30,
  [SMALL_STATE(5)] = 44,
  [SMALL_STATE(6)] = 50,
  [SMALL_STATE(7)] = 56,
  [SMALL_STATE(8)] = 62,
  [SMALL_STATE(9)] = 69,
  [SMALL_STATE(10)] = 76,
  [SMALL_STATE(11)] = 80,
  [SMALL_STATE(12)] = 84,
  [SMALL_STATE(13)] = 88,
  [SMALL_STATE(14)] = 92,
  [SMALL_STATE(15)] = 96,
  [SMALL_STATE(16)] = 100,
  [SMALL_STATE(17)] = 104,
  [SMALL_STATE(18)] = 108,
  [SMALL_STATE(19)] = 112,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [13] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(10),
  [16] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_blob_field, 5, 0, 0),
  [21] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_blob_field, 5, 0, 0),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_int_field, 5, 0, 0),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_blob_field, 6, 0, 0),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_blob_value, 2, 0, 0),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [39] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_int_value, 1, 0, 0),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_length, 1, 0, 0),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_bi(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
