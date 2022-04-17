void traverse(std::string& prefix, TrieNode const& node) {
  if (node.isWord)
    print(prefix);

  for (char index = 0; index < ALPHABET_SIZE; ++index) {
    char next = 'a'+index;
    TrieNode const* pChild = node.Child[index];
    if (pChild) {
      prefix.push_back(next);
      traverse(prefix, *pChild);
      prefix.pop_back();
    }
  }
}
