from cs50 import get_string

text = get_string("Text: ")
words = len(text.split())
full_stops = len(text.split(". "))
questions = len(text.split("? "))
if (questions > 1):
    sentences = full_stops + questions - 1
else:
    sentences = full_stops
letters = 0
for i in text:
    if (i.isalpha()):
        letters += 1

avg_letters = 100 * (letters/words)
avg_sentences = 100 * (sentences/words)

grade = round(0.0588 * avg_letters - 0.296 * avg_sentences - 15.8)

if (grade > 16):
    print("Grade 16+")
elif (grade < 1):
    print("Before Grade 1")
else:
    print(f"Grade {grade}")
