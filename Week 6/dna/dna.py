import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Wrong input")
        sys.exit(1)
    else:
        # Read database file into a variable
        database = []
        with open(sys.argv[1]) as file:
            reader = csv.DictReader(file)
            for row in reader:
                database.append(row)

        file = open(sys.argv[1], "r")
        header = file.readline().split("\n")[0].split(",")
        header.pop(0)
        file.close()

        # Read DNA sequence file into a variable
        file = open(sys.argv[2], "r")
        dna = file.read()
        file.close()

        # Find longest match of each STR in DNA sequence
        counter = {}
        index_match = 0
        for x in header:
            counter[x] = str(longest_match(dna, x))

        # Check database for matching profiles
        for row in database:
            for i in header:
                if counter[i] == row[i]:
                    index_match = index_match + 1
            if index_match == len(header):
                print(row["name"])
                exit(0)
            else:
                index_match = 0

        print("No match")
        exit(1)

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
