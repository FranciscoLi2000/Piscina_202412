#!/bin/sh
# add_chelou.sh - Add FT_NBR1 (base in'"?!) and FT_NBR2 (base mrdoc),
#                 display the sum in base "gtaio luSnemf".
#
# /*
#  * Positional numeral systems with arbitrary character sets:
#  *   Any ordered set of N distinct characters can serve as a base-N
#  *   digit alphabet. The first character = 0, second = 1, … last = N-1.
#  *
#  *   Bases used:
#  *     BASE1   = in'"?!        (6 chars  → base 6)
#  *     BASE2   = mrdoc         (5 chars  → base 5)
#  *     BASEOUT = gtaio luSnemf (13 chars → base 13)
#  *
#  * Conversion custom-base → decimal  (Horner's method):
#  *   For each digit character left-to-right:
#  *     decimal = decimal * base_size + position_of_digit_in_alphabet
#  *   Example: "ni" in BASE1 → (1)*6 + (0) = 6  ("n"=1, "i"=0)
#  *
#  * Conversion decimal → custom-base:
#  *   Repeatedly divide by base_size; remainders (read bottom-up)
#  *   give the digits of the result.
#  *
#  * bc: arbitrary-precision calculator (man bc)
#  *   Used here because FT_NBR2 in base 5 can have up to ~28 digits,
#  *   producing values near 3.7×10^19 — beyond shell $(( )) arithmetic
#  *   (signed 64-bit) and beyond awk's double-precision floats (~10^15).
#  *   bc handles integers of unlimited size.
#  *
#  * cut -c N : extract the Nth character of a line (1-indexed).
#  * wc -c   : count bytes (= characters for ASCII input).
#  * tr -d   : delete characters (used to strip whitespace from wc output).
#  */

BASE1=$(printf "in'\"?!")
BASE2="mrdoc"
BASEOUT=$(printf "gtaio luSnemf")

# char_pos: print the 0-based index of character $1 within string $2
char_pos()
{
    _c="$1"
    _base="$2"
    _len=$(printf '%s' "$_base" | wc -c | tr -d ' \t')
    _i=1
    while [ "$_i" -le "$_len" ]; do
        _bc=$(printf '%s' "$_base" | cut -c"$_i")
        if [ "$_bc" = "$_c" ]; then
            echo $((_i - 1))
            return
        fi
        _i=$((_i + 1))
    done
    echo "0"
}

# to_decimal: convert number string $1 in custom base $2 to decimal via bc
to_decimal()
{
    _num="$1"
    _base="$2"
    _blen=$(printf '%s' "$_base" | wc -c | tr -d ' \t')
    _nlen=$(printf '%s' "$_num"  | wc -c | tr -d ' \t')
    _expr="0"
    _i=1
    while [ "$_i" -le "$_nlen" ]; do
        _c=$(printf '%s' "$_num" | cut -c"$_i")
        _pos=$(char_pos "$_c" "$_base")
        _expr="($_expr) * $_blen + $_pos"
        _i=$((_i + 1))
    done
    printf '%s\n' "$_expr" | bc
}

# from_decimal: convert decimal number $1 to custom base $2
from_decimal()
{
    _num="$1"
    _base="$2"
    _blen=$(printf '%s' "$_base" | wc -c | tr -d ' \t')
    _result=""
    while [ "$(printf '%s > 0\n' "$_num" | bc)" = "1" ]; do
        _rem=$(printf '%s %% %s\n' "$_num" "$_blen" | bc)
        _c=$(printf '%s' "$_base" | cut -c"$((_rem + 1))")
        _result="${_c}${_result}"
        _num=$(printf '%s / %s\n' "$_num" "$_blen" | bc)
    done
    if [ -z "$_result" ]; then
        printf '%s' "$_base" | cut -c1
    else
        printf '%s\n' "$_result"
    fi
}

n1=$(to_decimal "$FT_NBR1" "$BASE1")
n2=$(to_decimal "$FT_NBR2" "$BASE2")
sum=$(printf '%s + %s\n' "$n1" "$n2" | bc)
from_decimal "$sum" "$BASEOUT"
