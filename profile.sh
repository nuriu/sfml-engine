program=''
tool=''

print_usage() {
  printf "\n  profile.sh is responsible from running valgrind tools.\n"
  printf "\n\tUsage: \n"
  printf "\t\tprofile.sh -t <valgrind-tool-to-use> -p <program-to-analyze>\n\n"
  printf "\t\tAvailable valgrind tools to use;\n"
  printf "\t\t memcheck\n"
  printf "\t\t cachegrind\n"
  printf "\t\t callgrind\n"
  printf "\t\t massif\n"
}

while getopts 'p:vt:v' flag; do
  case "${flag}" in
    p) program="${OPTARG}" ;;
    t) tool="${OPTARG}" ;;
    *) print_usage
    exit 1 ;;
  esac
done

if [[ -n ${program} ]] && [[ -n ${tool} ]]; then
  if [[ ${tool} == 'memcheck' ]]; then
    valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all $program
  elif [[ ${tool} == 'cachegrind' ]]; then
    valgrind --tool=cachegrind --cachegrind-out-file=cachegrind.out $program
  elif [[ ${tool} == 'callgrind' ]]; then
    valgrind --tool=callgrind --callgrind-out-file=callgrind.out $program
  elif [[ ${tool} == 'massif' ]]; then
    valgrind --tool=massif --time-unit=B --massif-out-file=massif.out $program
  fi
else
    print_usage
fi

printf "\n"
