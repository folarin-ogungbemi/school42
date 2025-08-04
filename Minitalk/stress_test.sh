#!/bin/bash

SERVER_PID=$1
LOG_FILE="minitalk_stress_test.log"
CLIENT="./client"

if [ -z "$SERVER_PID" ]; then
    echo "Usage: $0 <SERVER_PID>"
    exit 1
fi

echo "Minitalk Stress Test Log" > "$LOG_FILE"
echo "Target Server PID: $SERVER_PID" >> "$LOG_FILE"
echo "Timestamp: $(date)" >> "$LOG_FILE"
echo "----------------------------------" >> "$LOG_FILE"

run_test() {
    local message="$1"
    local description="$2"

    echo -n "Testing: $description... "
    start_time=$(date +%s.%N)
    $CLIENT "$SERVER_PID" "$message" > /dev/null
    status=$?
    end_time=$(date +%s.%N)
    elapsed=$(echo "$end_time - $start_time" | bc)

    if [ "$status" -eq 0 ]; then
        echo "✅ [${elapsed}s]"
        echo "Test: $description | Time: ${elapsed}s | Status: OK" >> "$LOG_FILE"
    else
        echo "❌ FAILED"
        echo "Test: $description | Time: ${elapsed}s | Status: FAILED" >> "$LOG_FILE"
    fi
}

### === TEST CASES === ###

run_test "Hello" "Short message"
run_test "" "Empty string"
run_test "$(printf '%.0sA' {1..10})" "10 characters"
run_test "$(printf '%.0sB' {1..100})" "100 characters"
run_test "$(printf '%.0sC' {1..250})" "250 characters"
run_test "$(printf '%.0sD' {1..500})" "500 characters"
run_test "$(printf '%.0sE' {1..1000})" "1000 characters"

run_test "!@#$%^&*()_+[]{}|;:',.<>/?~" "Special characters"
run_test "こんにちは世界" "Unicode (non-ASCII, may be broken unless handled)"
run_test "This is a test with spaces in between words." "String with spaces"

### === MULTIPLE MESSAGES IN A ROW === ###
for i in {1..5}; do
    run_test "Batch Message #$i" "Sequential message $i"
done

### === BATCH TEST: Rapid Sending === ###
echo -n "Batch stress test (50 short messages)... "
batch_status=0
start_time=$(date +%s.%N)
for i in {1..50}; do
    $CLIENT "$SERVER_PID" "msg$i" > /dev/null || batch_status=1
done
end_time=$(date +%s.%N)
elapsed=$(echo "$end_time - $start_time" | bc)
if [ "$batch_status" -eq 0 ]; then
    echo "✅ [${elapsed}s]"
    echo "Batch: 50 short messages | Time: ${elapsed}s | Status: OK" >> "$LOG_FILE"
else
    echo "❌ FAILED"
    echo "Batch: 50 short messages | Time: ${elapsed}s | Status: FAILED" >> "$LOG_FILE"
fi

### === FINAL === ###
echo "----------------------------------" >> "$LOG_FILE"
echo "Done. Full log in $LOG_FILE"

