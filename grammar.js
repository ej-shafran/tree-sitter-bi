module.exports = grammar({
  name: "bi",

  extras: () => ["\r"],

  rules: {
    document: ($) => "hello",
  },
});
