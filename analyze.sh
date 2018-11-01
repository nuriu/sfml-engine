file=''

print_usage() {
  printf "\nanalyze.sh is responsible from running static code analysises.\n"
  printf "\n\tUsage: \n"
  printf "\t\tanalyze.sh -f <file-to-analyze>\n"
}

while getopts 'f:v' flag; do
  case "${flag}" in
    f) file="${OPTARG}" ;;
    *) print_usage
    exit 1 ;;
  esac
done

if [[ -n ${file} ]]; then
  echo ""
  printf "clang-tidy results:\n\n"

  clang-tidy $file -checks=* -- -I include/

  echo ""
  echo "-----------------------"

  printf "\ncppcheck results:\n\n"

  cppcheck $file -I include/ --enable=all --inconclusive --quiet
else
  echo ""
  printf "clang-tidy results:\n\n"

  clang-tidy src/* -checks=bugprone-*,cert-*,cppcoreguidelines-*,clang-analyzer-*,hicpp-*,misc-*,modernize-*,performance-*,portability-*,readability-* -- -I include/

  echo ""
  echo "-----------------------"

  printf "\ncppcheck results:\n\n"

  cppcheck src/* -I include/ --enable=all --inconclusive --quiet
fi

printf "\n"
