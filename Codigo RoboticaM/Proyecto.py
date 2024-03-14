import time
import math as m
import numpy as np
import scipy.interpolate as spi
from coppeliasim_zmqremoteapi_client import RemoteAPIClient

class robotDDR:
    def v2u(v, omega, r, L):
        ur = v/r + L*omega/(2*r)
        ul = v/r - L*omega/(2*r)
        return ur, ul
    def setVelocidad(mL, mR, ur, ul):
        sim.setJointTargetVelocity(motorL, ul)
        sim.setJointTargetVelocity(motorR, ur)

class sensores:
    pass

class mapeo:
    def q2R(x,y,z,w):
        R = np.zeros((3,3))
        R[0,0] = 1-2*(y**2+z**2)
        R[0,1] = 2*(x*y-z*w)
        R[0,2] = 2*(x*z+y*w)
        R[1,0] = 2*(x*y+z*w)
        R[1,1] = 1-2*(x**2+z**2)
        R[1,2] = 2*(y*z-x*w)
        R[2,0] = 2*(x*z-y*w)
        R[2,1] = 2*(y*z+x*w)
        R[2,2] = 1/2*(x**2+y**2)
        return R


client = RemoteAPIClient()
sim = client.getObject('sim')

print('Program started')

motorL = sim.getObject("/PioneerP3DX/leftMotor")
motorR = sim.getObject("/PioneerP3DX/rightMotor")
robot  = sim.getObject("/PioneerP3DX")

r = 0.5*0.195
L = 2.0*0.1655
occgrid=[]
tocc=[]

sim.startSimulation()


while sim.getSimulationTime() < 5:
    ur, ul = robotDDR.v2u(10, 2.0*m.pi/15.0, r, L)
    robotDDR.setVelocidad(motorL, motorR, ur, ul)


sim.pauseSimulation()


sim.stopSimulation()