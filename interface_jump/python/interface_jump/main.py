from PySide2 import QtCore, QtGui, QtWidgets
from PySide2.QtWidgets import *
from login import *
import sys
import os



if __name__ == '__main__':
    app = QApplication(sys.argv)
    m_login = Ui_login_form()
    login_window = QWidget()
    m_login.setupUi(login_window)
    login_window.show()
    sys.exit(app.exec_())
