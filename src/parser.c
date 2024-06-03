#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 17
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 13
#define ALIAS_COUNT 0
#define TOKEN_COUNT 9
#define EXTERNAL_TOKEN_COUNT 2
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 7
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  anon_sym_COLONi = 1,
  anon_sym_SPACE = 2,
  anon_sym_LF = 3,
  sym_int_value = 4,
  anon_sym_COLONb = 5,
  sym_identifier = 6,
  sym_blob_value = 7,
  sym_length = 8,
  sym_document = 9,
  sym_int_field = 10,
  sym_blob_field = 11,
  aux_sym_document_repeat1 = 12,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_COLONi] = "field_marker",
  [anon_sym_SPACE] = " ",
  [anon_sym_LF] = "\n",
  [sym_int_value] = "int_value",
  [anon_sym_COLONb] = "field_marker",
  [sym_identifier] = "identifier",
  [sym_blob_value] = "blob_value",
  [sym_length] = "length",
  [sym_document] = "document",
  [sym_int_field] = "int_field",
  [sym_blob_field] = "blob_field",
  [aux_sym_document_repeat1] = "document_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_COLONi] = anon_sym_COLONi,
  [anon_sym_SPACE] = anon_sym_SPACE,
  [anon_sym_LF] = anon_sym_LF,
  [sym_int_value] = sym_int_value,
  [anon_sym_COLONb] = anon_sym_COLONi,
  [sym_identifier] = sym_identifier,
  [sym_blob_value] = sym_blob_value,
  [sym_length] = sym_length,
  [sym_document] = sym_document,
  [sym_int_field] = sym_int_field,
  [sym_blob_field] = sym_blob_field,
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
  [sym_int_value] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COLONb] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
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
  [sym_document] = {
    .visible = true,
    .named = true,
  },
  [sym_int_field] = {
    .visible = true,
    .named = true,
  },
  [sym_blob_field] = {
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(4);
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == '\r') SKIP(0);
      if (lookahead == ' ') ADVANCE(6);
      if (lookahead == ':') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(8);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(10);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(9);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(5);
      END_STATE();
    case 3:
      if (lookahead == 'b') ADVANCE(1);
      if (lookahead == 'i') ADVANCE(2);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_COLONi);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_SPACE);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_LF);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_int_value);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(8);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_COLONb);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(10);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0, .external_lex_state = 2},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0, .external_lex_state = 3},
  [16] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_COLONi] = ACTIONS(1),
    [anon_sym_SPACE] = ACTIONS(1),
    [anon_sym_LF] = ACTIONS(1),
    [sym_int_value] = ACTIONS(1),
    [anon_sym_COLONb] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [sym_blob_value] = ACTIONS(1),
    [sym_length] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(8),
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
  [30] = 1,
    ACTIONS(19), 3,
      ts_builtin_sym_end,
      anon_sym_COLONi,
      anon_sym_COLONb,
  [36] = 1,
    ACTIONS(21), 3,
      ts_builtin_sym_end,
      anon_sym_COLONi,
      anon_sym_COLONb,
  [42] = 1,
    ACTIONS(23), 1,
      sym_identifier,
  [46] = 1,
    ACTIONS(25), 1,
      sym_identifier,
  [50] = 1,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
  [54] = 1,
    ACTIONS(29), 1,
      anon_sym_SPACE,
  [58] = 1,
    ACTIONS(31), 1,
      anon_sym_SPACE,
  [62] = 1,
    ACTIONS(33), 1,
      sym_int_value,
  [66] = 1,
    ACTIONS(35), 1,
      sym_length,
  [70] = 1,
    ACTIONS(37), 1,
      anon_sym_LF,
  [74] = 1,
    ACTIONS(39), 1,
      anon_sym_LF,
  [78] = 1,
    ACTIONS(41), 1,
      sym_blob_value,
  [82] = 1,
    ACTIONS(43), 1,
      anon_sym_LF,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 15,
  [SMALL_STATE(4)] = 30,
  [SMALL_STATE(5)] = 36,
  [SMALL_STATE(6)] = 42,
  [SMALL_STATE(7)] = 46,
  [SMALL_STATE(8)] = 50,
  [SMALL_STATE(9)] = 54,
  [SMALL_STATE(10)] = 58,
  [SMALL_STATE(11)] = 62,
  [SMALL_STATE(12)] = 66,
  [SMALL_STATE(13)] = 70,
  [SMALL_STATE(14)] = 74,
  [SMALL_STATE(15)] = 78,
  [SMALL_STATE(16)] = 82,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [13] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(6),
  [16] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_int_field, 5, 0, 0),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_blob_field, 7, 0, 0),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [27] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token_blob_value = 0,
  ts_external_token_length = 1,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token_blob_value] = sym_blob_value,
  [ts_external_token_length] = sym_length,
};

static const bool ts_external_scanner_states[4][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token_blob_value] = true,
    [ts_external_token_length] = true,
  },
  [2] = {
    [ts_external_token_length] = true,
  },
  [3] = {
    [ts_external_token_blob_value] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_bi_external_scanner_create(void);
void tree_sitter_bi_external_scanner_destroy(void *);
bool tree_sitter_bi_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_bi_external_scanner_serialize(void *, char *);
void tree_sitter_bi_external_scanner_deserialize(void *, const char *, unsigned);

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
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_bi_external_scanner_create,
      tree_sitter_bi_external_scanner_destroy,
      tree_sitter_bi_external_scanner_scan,
      tree_sitter_bi_external_scanner_serialize,
      tree_sitter_bi_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
