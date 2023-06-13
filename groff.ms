\" This is an example groff document
.TL
Title
.AU
Author Institute
\" To compile:
\" groff -ms file.ms -Tpdf >file.pdf
\" To read in zathura:
\" groff -ms file.ms -Tpdf | zathura -
\" To compile with eqn:
\" groff -e file.ms -ms -T pdf >file.pdf
\" or
\" eqn file.ms -Tpdf | groff -ms -Tpdf >file.pdf
\"Abstract Begin
.AB
This is an abstract.
.AE
\"Abstract End

.NH
New Heading
.NH 2
Subsection
.PP
Here is some text. I want the word
.B "bold"
to be bold.
.B "BOLD" !
.B "Bald" ). (
.UL underlined
.BX "im in a box"
We can have
.I "italic text"
with .I.
.BI "This is bold italic text."
.PP
Another paragraph here
.RS
.PP
Indented paragraph here
.RE
.PP
Now it's back to normal
.SH
Non-numbered heading
.PP
Hey.
.IP
A good point
.IP
A nice point
.IP
AN EPIC POINT
.IP \(bu 2
bulleted
.IP \(bu 4
bulleted
.IP \(bu 6
bulleted

.de BL
.IP \(bu 8
..
.BL
noice macro
.so macros
.BU
macro from a file
.NH
Formatting Maths with eqn
.PP
Here is a
.B "cool"
demo:
.EQ
x = 3 + 5
.EN
.EQ
x >= 3 +- 5
.EN
.EQ
b sup 2 - 4ac
.EN
.EQ
b sub {2 - 4ac}
.EN
.EQ
phi = {1 + sqrt 5} over 2
.EN
.EQ
x = 
sqrt {
{sum from i=1 to N ( x sub i - x bar ) sup 2}
over
N-1
}
.EN
.EQ
DELTA x = v sub 0 t + 1 over 2 at sup 2
.EN
*
x = 3
x = 5

x = 9
*
