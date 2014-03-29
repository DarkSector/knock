import os
import serial
from flask import Flask, jsonify, request, render_template
KNOCK_PORT = '/dev/tty.usbserial-A900XXQH'
BAUD_RATE = 19200