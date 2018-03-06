file(REMOVE_RECURSE
  "uf_test.pdb"
  "uf_test"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/uf_test.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
