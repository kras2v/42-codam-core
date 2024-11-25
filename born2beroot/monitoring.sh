#!/bin/bash

ARCHITECTURE=$(uname -a) #
pCPU=$(lscpu | grep "^Socket(s):" | awk '{print $2}') #
vCPU=$(lscpu | grep "^CPU(s):" | awk '{print $2}') #
fRAM=$(free -m | grep "^Mem" | awk '{print $2}') #
uRAM=$(free -m | grep "^Mem" | awk '{print $3}') #
pRAM=$(awk -v used="$uRAM" -v total="$fRAM" \
'BEGIN {printf "%.2f", (used / total) * 100}') #

fDISK=$(df -BG | grep "^/dev/" | grep -v "/boot$" | awk '{fDGb += $2} END {print fD>
uDISK=$(df -BM | grep "^/dev/" | grep -v "/boot$" | awk '{uDMb += $3} END {print uD>
pDISK=$(df -BM | grep "^/dev/" | grep -v "/boot$" | \
awk -v uDMb="$uDISK" '{fDMb += $2} END {printf "%d", (uDMb / (fDMb)) * 100}')
uCPU=$(top -n1 | grep "^%Cpu" | awk '{us = $2} {sy = $4} END {printf "%.1f", us+sy}>
lboot=$(who -b | awk '{print $3" "$4}')
LVM=$(lsblk | grep "lvm" | wc -l)
if [ "$LVM" -gt 0 ]; then
        isLVM=yes
else
        isLVM=no
fi

TCPs=$(netstat -na | grep "ESTABLISHED" | wc -l)
USERs=$(who | wc -l)
IP=$(hostname -I)
MAC=$(ip address | grep ether | awk '{print $2}')
SUDOs=$(journalctl | grep sudo | grep COMMAND | wc -l)

wall "  #Architecture : $ARCHITECTURE
        #CPU physical : $pCPU
        #vCPU : $vCPU
        #Memory Usage : $uRAM/${fRAM}MB (${pRAM}%)
        #Disk Usage : $uDISK/${fDISK} (${pDISK}%)
        #CPU load: ${uCPU}%
        #Last boot: $lboot
        #LVM use: $isLVM
        #Connections TCP : $TCPs ESTABLISHED
        #User log: $USERs
        #Network: IP $IP (${MAC})
        #Sudo : $SUDOs cmd"

