## SofiMake-v0.1
# A tool that generates Sofistik FEA Sofiload module load combinations based on Autodesk Robot LC export.

The load combinations should be exported with their labels in the following format:
- ULS: SGN/ 9;STA1*1.10 + STA2*1.30 + STA3*1.20 + EKSP1*1.20 + EKSP2*1.20 + EKSP3*1.20
- SLS: SGU/ 226;STA1*1.00 + STA2*1.00 + STA3*1.00 + EKSP6*1.00 + EKSP7*1.00 + EKSP8*1.00

Dead load labels: STA1, STA2, ...

Live load labels (including wind, snow, etc.): EKSP1, EKSP2, ...

Required filename of the Autodesk Robot LC export: komb_robot.csv. 

The file should be encoded to UTF-8! Using the standard Windows UTF-16 LE encoding will result in failure.


# Usage: 

After compiling place the CSV file in the same directory as the exe file. 

Execute the program - a TXT file will be created with the formatting of the module Sofiload.

ULS load combinations start from LC 1001, SLS load combinations start from LC 1301.

# Example of a generated Sofiload load case:
LC 1003 TITL 'STA1*1.10  STA2*1.30  STA3*1.20  EKSP1*1.20' TYPE (D)

COPY 1 FACT 1.1

COPY 2 FACT 1.3

COPY 3 FACT 1.2

COPY 4 FACT 1.2
