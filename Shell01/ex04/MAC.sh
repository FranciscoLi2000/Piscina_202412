#!/bin/sh
# MAC.sh - Display the MAC address of every network interface,
#          one address per line.
#
# /*
#  * ifconfig: configure and display network interface parameters (man ifconfig)
#  *   Without arguments it lists all active interfaces with their
#  *   current settings: IP address, netmask, flags, statistics, etc.
#  *
#  * A MAC address (Media Access Control address) is a 48-bit hardware
#  * identifier permanently assigned to a Network Interface Controller (NIC).
#  * It is written as six pairs of hexadecimal digits separated by colons:
#  *   e.g.  08:00:27:4b:e2:1a
#  *
#  * On Linux and macOS, ifconfig labels each MAC address with the
#  * keyword "ether" on the same line.
#  *
#  * grep ether: keep only lines that contain the word "ether"
#  *
#  * awk '{print $2}': split the line on whitespace and print the
#  *   second field, which is the MAC address that follows "ether".
#  *
#  * Each address is printed on its own line by awk's print statement.
#  */
ifconfig | grep ether | awk '{print $2}'
