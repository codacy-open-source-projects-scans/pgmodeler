# XML definition for custom index for a single column or constraint
# CAUTION: Do not modify this file unless you know what you are doing.
# Code generation can be broken if incorrect changes are made.

%if {index} %then $tb %end
$tb [<object name=] "&{name}"

%if {index} %then [ index=] "{index}" %end
%if {parent} %then [ parent=] "&{parent}" %end
%if {type} %then [ type=] "{type}" %end

/> $br
