# Electronic_Vote
The program reads the personal data file of the people who will vote from a CSV (Comma Separated Values) file called "evidenta.csv" written in the following format (each person on one line):

LAST_NAME FIRST_NAME_1 FIRST_NAME_2 FIRST_NAME_N, ADDRESS, IDENTITY_NUMBER, ID_SERIES
The number of people is not known when the file is opened; the file will be read to its end.

Lines of the form are read from the keyboard:

+ VOTER_IDENTITY_NUMBER CANDIDATE_FULL_NAME
or
?
or
*

Depending on the first character, the following actions will be performed:

'+' - someone is trying to vote. The following checks are carried out:

If the IDENTITY_NUMBER does not exist in the database, an error message is displayed: "Invalid IDENTITY_NUMBER" and it is considered a fraud attempt

If the IDENTITY_NUMBER exists, but the person has already voted, "Vote already registered" error message is displayed and it is considered attempted fraud

If the IDENTITY_NUMBER exists but the person's age is less than 18 (the difference between the year and month of the IDENTITY_NUMBER and the current year and month is calculated) an error message "Minor person" is displayed and it is NOT considered a fraud attempt

Otherwise, the vote for the candidate specified by name is recorded and the voter's IDENTITY_NUMBER is marked as the vote cast.

'?' - current statistics are required: Candidates will be displayed in descending order of votes obtained (if there are several candidates with the same number of votes, the order in which they are displayed is the order in which they appeared in the list for the first time) and the number of fraud attempts

'*' - the electroral process ends, the statistic is displayed similar to the output for '?' and the program ends

Displaying statistics when entering a '?' or '*' is done in the following format:

Statistics
----------
NAME CANDIDATE_1: 1234 votes (77.61%)
NAME CANDIDATE_2: 343 votes (21.57%)
NAME CANDIDATE_N: 13 votes (0.82%)
Fraud attempts: 2

