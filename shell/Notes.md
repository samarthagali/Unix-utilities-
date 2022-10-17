## future fixes

### fix 1 (complete by 08/10/2022)

fix inability to write to files

Actual command with output:
```
sam-shell>mrev t6.txt t7.txt
in rev
sam-shell>mcat t7.txt
in reader
t7.txt

sam-shell>quit
```
Expected output:
```
sam-shell>mrev t6.txt t7.txt
in rev
sam-shell>mcat t7.txt
bye bye
welcome to the jungle
hi my name is sam
```
fixes made : writing works for mcat not mrev - update mrev after fix 2

### fix 2 (complete by 11/10/2022)

ensure program stores previous commands upto a certain extent(previous 20 commands)

**fix2 done**



