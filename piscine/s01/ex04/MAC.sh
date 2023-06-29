#!/bin/sh
ifconfig | grep ether | sed -d " ether "