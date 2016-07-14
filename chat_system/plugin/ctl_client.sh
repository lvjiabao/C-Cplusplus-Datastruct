#!/bin/bash

ROOT_PATH=$(pwd)
BIN=$ROOT_PATH/udp_client
CONF=$ROOT_PATH/conf/conf

proc=$0
function usage()
{
	printf "%s%s\n" "Usage: " "$proc [start(-s) | stop(-t) ]"
}

function is_server_exist()
{
	fun=$(basename $BIN)
	ret=$(pidof $fun)
	if [ -z "$ret" ];then
		return 1
	else
		return 0
	fi
}

function start_client()
{
	if is_server_exist ; then
		echo "client is already exist !"
		return 
	else
		#IP=$(grep -E '_IP_' $CONF | awk -F: '{print $NF}')
		#PORT=$(grep -E '_PORT_' $CONF | awk -F: '{print $NF}')
		IP="127.0.0.1"
		PORT="8080"
		$BIN $IP $PORT
	fi
}

function stop_client()
{
	fun=$(basename $BIN)
	if is_server_exist ; then
		pid=$(pidof $fun)
		echo "PID : $pid"
		kill -9 $pid
	else
		echo "client is not exist !"
	fi
}

if [ $# -ne 1 ];then
	usage
	exit 1
fi

case $1 in
	'start' | '-s')
	start_client
	;;
	'stop' | '-t')
	stop_client
	;;
	*)
	usage
	exit 2
	;;
esac


