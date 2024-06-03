module.exports = grammar({
  name: "bi",

  extras: () => ["\r"],

  rules: {
    document: ($) => repeat(choice($.int_field, $.blob_field)),

    int_field: ($) =>
      seq(alias(":i ", $.field_marker), $.identifier, " ", $.int_value, "\n"),
    int_value: () => /\d+/,

    blob_field: ($) =>
      seq(
        alias(":b ", $.field_marker),
        $.identifier,
        " ",
        $.length,
        "\n",
        optional($.blob_value),
      ),
    // TODO: external scanner
    blob_value: () => seq(/.+/, "\n"),
    length: () => /\d+/,

    identifier: () => /[A-Za-z]+/,
  },
});
