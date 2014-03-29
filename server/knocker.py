import os
import serial
from flask import Flask, jsonify, request
KNOCK_PORT = '/dev/ttyUSB0'
BAUD_RATE = 19200
#from __init__ import KNOCK_PORT, BAUD_RATE

app = Flask(__name__)


@app.route('/')
def webstatus():
	return "Knock work"


@app.route('/knocker', methods=['POST'])
def knocker():
	if request.method == 'POST':
		ser = serial.Serial()
		ser.port = KNOCK_PORT
		ser.baudrate = BAUD_RATE
		ser.open()
		threshold = 10
		x = []
		if ser.isOpen():
			for i in range(0,30):
				y = ser.readline().replace('/r/n','')
				temp = y.split(':')
				if temp[0] == 'PIEZO':
					x.append(int(temp[1]))
		ser.close()
		summation = 0
		for x_val in x:
			summation = summation + xval
		data_dict = {'ldr': '', 'piezo': summation}

	return jsonify(**data_dict)


if __name__ == '__main__':
	server_host = '0.0.0.0'
	port_number = 60000
	app.run(host=server_host, port=port_number)
