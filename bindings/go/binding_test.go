package tree_sitter_bi_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-bi"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_bi.Language())
	if language == nil {
		t.Errorf("Error loading Bi grammar")
	}
}
