#!/usr/bin/env bash
file=''
changed_files=$(git diff --name-only HEAD | grep -E '.*\.(hpp|cpp)$' | cut -f 2)

while getopts 'f:v' flag; do
  case "${flag}" in
    f) file="${OPTARG}"
    exit 1 ;;
  esac
done

if [[ -n ${file} ]]; then
  clang-format -style=file -i ${file}

  echo ""
  printf "\ncppcheck results:\n\n"
  cppcheck ${file} -I include/ -I /usr/include/ -I lib/spdlog/include/ -I lib/imgui/ -I lib/imgui-sfml/ -I lib/tmxlite/tmxlite/include/ --enable=all --inconclusive --quiet

  echo ""
  echo "-----------------------"
  printf "clang-tidy results:\n\n"
  clang-tidy ${file} -checks=* -- -I include/ -I /usr/include/ -I lib/spdlog/include/ -I lib/imgui/ -I lib/imgui-sfml/ -I lib/tmxlite/tmxlite/include/
else
  clang-format -style=file -i ${changed_files}

  echo ""
  printf "\ncppcheck results:\n\n"
  cppcheck ${changed_files} -I include/ -I lib/spdlog/include/ -I lib/imgui/ -I lib/imgui-sfml/ -I lib/tmxlite/tmxlite/include/ --enable=all --inconclusive --quiet --force

  echo ""
  echo "-----------------------"
  printf "clang-tidy results:\n\n"
  clang-tidy ${changed_files} -- -I include/ -I /usr/include/ -I lib/spdlog/include/ -I lib/imgui/ -I lib/imgui-sfml/ -I lib/tmxlite/tmxlite/include/
fi

printf "\n"
