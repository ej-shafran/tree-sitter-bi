#include "tree_sitter/alloc.h"
#include "tree_sitter/parser.h"
#include <ctype.h>
#include <stdbool.h>

typedef enum { BLOB_VALUE, LENGTH } TokenType;

typedef struct {
  int count;
} Scanner;

static bool parse_length(Scanner *s, TSLexer *lexer,
                         const bool *valid_symbols) {

  if (!valid_symbols[LENGTH])
    return false;

  if (!isdigit(lexer->lookahead))
    return false;

  int value = 0;
  while (isdigit(lexer->lookahead)) {
    value *= 10;
    value += lexer->lookahead - '0';
    lexer->advance(lexer, false);
  }

  s->count = value;
  lexer->result_symbol = LENGTH;
  return true;
}

static bool parse_blob_value(Scanner *s, TSLexer *lexer,
                             const bool *valid_symbols) {
  if (!valid_symbols[BLOB_VALUE])
    return false;

  for (int i = 0; i < s->count; i++) {
    if (lexer->eof(lexer))
      break;

    lexer->advance(lexer, false);
  }

  lexer->result_symbol = BLOB_VALUE;
  return true;
}

/* This function should create your scanner object. It will only be called once
 * anytime your language is set on a parser. Often, you will want to allocate
 * memory on the heap and return a pointer to it. If your external scanner
 * doesn't need to maintain any state, it's ok to return NULL.
 */
void *tree_sitter_bi_external_scanner_create(void) {
  Scanner *s = (Scanner *)ts_malloc(sizeof(Scanner));

  s->count = 0;

  return s;
}

/* This function should free any memory used by your scanner. It is called once
 * when a parser is deleted or assigned a different language. It receives as an
 * argument the same pointer that was returned from the create function. If your
 * create function didn’t allocate any memory, this function can be a noop.
 */
void tree_sitter_bi_external_scanner_destroy(void *payload) {
  Scanner *s = (Scanner *)s;
  ts_free(s);
}

/* This function should copy the complete state of your scanner into a given
 * byte buffer, and return the number of bytes written. The function is called
 * every time the external scanner successfully recognizes a token. It receives
 * a pointer to your scanner and a pointer to a buffer. The maximum number of
 * bytes that you can write is given by the
 * TREE_SITTER_SERIALIZATION_BUFFER_SIZE constant, defined in the
 * tree_sitter/parser.h header file.
 *
 * The data that this function writes will ultimately be stored in the syntax
 * tree so that the scanner can be restored to the right state when handling
 * edits or ambiguities. For your parser to work correctly, the serialize
 * function must store its entire state, and deserialize must restore the entire
 * state. For good performance, you should design your scanner so that its state
 * can be serialized as quickly and compactly as possible.
 */
unsigned tree_sitter_bi_external_scanner_serialize(void *payload,
                                                   char *buffer) {
  // TODO
  return 0;
}

/* This function should restore the state of your scanner based the bytes that
 * were previously written by the serialize function. It is called with a
 * pointer to your scanner, a pointer to the buffer of bytes, and the number of
 * bytes that should be read. It is good practice to explicitly erase your
 * scanner state variables at the start of this function, before restoring their
 * values from the byte buffer.
 */
void tree_sitter_bi_external_scanner_deserialize(void *payload,
                                                 const char *buffer,
                                                 unsigned length) {
  // TODO
}

/* This function is responsible for recognizing external tokens. It should
 * return true if a token was recognized, and false otherwise. It is called with
 * a “lexer” struct with the following fields:
 *
 * int32_t lookahead - The current next character in the input stream,
 * represented as a 32-bit unicode code point.
 *
 * TSSymbol result_symbol - The symbol that was recognized. Your scan function
 * should assign to this field one of the values from the TokenType enum,
 * described [here](https://tree-sitter.github.io/tree-sitter/creating-parsers).
 *
 * void (*advance)(TSLexer *, bool skip) - A function for advancing to the next
 * character. If you pass true for the second argument, the current character
 * will be treated as whitespace; whitespace won’t be included in the text range
 * associated with tokens emitted by the external scanner.
 *
 * void (*mark_end)(TSLexer *) - A function for marking the end of the
 * recognized token. This allows matching tokens that require multiple
 * characters of lookahead. By default (if you don’t call mark_end), any
 * character that you moved past using the advance function will be included in
 * the size of the token. But once you call mark_end, then any later calls to
 * advance will not increase the size of the returned token. You can call
 * mark_end multiple times to increase the size of the token.
 *
 * uint32_t (*get_column)(TSLexer *) - A function for querying the current
 * column position of the lexer. It returns the number of codepoints since the
 * start of the current line. The codepoint position is recalculated on every
 * call to this function by reading from the start of the line.
 *
 * bool (*is_at_included_range_start)(const TSLexer *) - A function for checking
 * whether the parser has just skipped some characters in the document. When
 * parsing an embedded document using the ts_parser_set_included_ranges function
 * (described in the multi-language document section), the scanner may want to
 * apply some special behavior when moving to a disjoint part of the document.
 * For example, in EJS documents, the JavaScript parser uses this function to
 * enable inserting automatic semicolon tokens in between the code directives,
 * delimited by <% and %>.
 *
 * bool (*eof)(const TSLexer *) - A function for determining whether the lexer
 * is at the end of the file. The value of lookahead will be 0 at the end of a
 * file, but this function should be used instead of checking for that value
 * because the 0 or “NUL” value is also a valid character that could be present
 * in the file being parsed.
 *
 * The third argument to the scan function is an array of booleans that
 * indicates which of external tokens are currently expected by the parser. You
 * should only look for a given token if it is valid according to this array. At
 * the same time, you cannot backtrack, so you may need to combine certain
 * pieces of logic.
 */
bool tree_sitter_bi_external_scanner_scan(void *payload, TSLexer *lexer,
                                          const bool *valid_symbols) {

  Scanner *s = (Scanner *)payload;

  if (parse_length(s, lexer, valid_symbols)) {
    return true;
  }

  if (parse_blob_value(s, lexer, valid_symbols)) {
    return true;
  }

  return false;
}
