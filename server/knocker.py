from server import Flask, serial, jsonify, request
from server import KNOCK_PORT, BAUD_RATE

@app.route('/')
def webstatus():
	return "hello"


@app.route('/knocker', requests=['POST'])
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
				y = ser.readline()
				temp = y.split(':')
				if temp[0] == 'PIEZO':
					x.append(int(temp[1]))
		summation = 0
		for x_val in x:
			summation = summation + xval
		data_dict = {'ldr': '', 'piezo': summation}

	return jsonify(**data_dict)