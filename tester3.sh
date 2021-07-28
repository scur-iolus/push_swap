>output
ARG="1 2 3" && ./push_swap $ARG | ./checker_Mac $ARG >> output
ARG="2 1 3" && ./push_swap $ARG | ./checker_Mac $ARG >> output
ARG="3 1 2" && ./push_swap $ARG | ./checker_Mac $ARG >> output
ARG="1 3 2" && ./push_swap $ARG | ./checker_Mac $ARG >> output
ARG="2 3 1" && ./push_swap $ARG | ./checker_Mac $ARG >> output
ARG="3 2 1" && ./push_swap $ARG | ./checker_Mac $ARG >> output
grep -c OK output | tr -d '\n'
echo "/" | tr -d '\n'
grep -c ".*" output
