#!/bin/bash

# Usage: ./stress_test.sh <server_pid>
# Example: ./stress_test.sh 3647958

if [ $# -ne 1 ]; then
    echo "Usage: $0 <server_pid>"
    exit 1
fi

SERVER_PID=$1
CLIENT=./client
LOG=stress_test.log

# Clear previous log
echo "Minitalk Stress Test Log" > "$LOG"

run_test() {
    local len=$1
    local char=${2:-A}
    local msg=$(printf "${char}%.0s" $(seq 1 $len))

    echo -ne "Sending $len characters... "

    # Measure the time it takes
    result=$( { /usr/bin/time -f "REAL:%e USER:%U SYS:%S" $CLIENT $SERVER_PID "$msg"; } 2>&1 )

    # Extract output
    real_time=$(echo "$result" | grep 'REAL' | awk -F ':' '{print $2}' | xargs)
    error_msg=$(echo "$result" | grep "Error")

    if [ -z "$error_msg" ]; then
        echo "✅ Passed in ${real_time}s"
        echo "Test: $len chars | Time: $real_time s | Status: OK" >> "$LOG"
    else
        echo "❌ Failed"
        echo "Test: $len chars | Time: $real_time s | Error: $error_msg" >> "$LOG"
    fi
}

# Test different message lengths
for size in 10 100 250 500 1000 2000; do
    run_test $size
    sleep 1
done

echo
echo "All tests done. See $LOG for details."

