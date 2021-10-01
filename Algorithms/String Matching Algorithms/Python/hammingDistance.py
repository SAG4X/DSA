##Hamming distance is a metric for comparing two binary data strings.
##While comparing two binary strings of equal length,
##Hamming distance is the number of bit positions in which the two bits are
##different.

def hamming_distance(string1, string2):
    dist_counter = 0
    for n in range(len(string1)):
        if string1[n] != string2[n]:
            dist_counter += 1
    return dist_counter

x=input("Enter 1st string:  ")
y=input("Enter 2nd string:  ")
print(hamming_distance(x,y))
