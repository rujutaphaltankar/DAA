n = int(input("Enter number of characters: "))

arr = []

print("Enter the characters:")
for i in range(n):
    ch = input().lower()
    arr.append(ch)

# Frequency array for 26 lowercase alphabets
freq = [0] * 26

print("Output:")

for i in range(n):
    # Update frequency of current character
    index = ord(arr[i]) - ord('a')
    freq[index] += 1

    found = False

    # Find the first non-repeating character
    for j in range(i + 1):
        index2 = ord(arr[j]) - ord('a')

        if freq[index2] == 1:
            print(arr[j], end=" ")
            found = True
            break

    # If no non-repeating character exists
    if not found:
        print("$", end=" ")

print()
