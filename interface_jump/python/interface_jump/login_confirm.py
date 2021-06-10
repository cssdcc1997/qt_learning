# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'login_confirm.ui'
#
# Created by: PyQt5 UI code generator 5.15.4
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PySide2 import QtCore, QtGui, QtWidgets
from PySide2.QtWidgets import *


class Ui_login_info_form(QWidget):
    def __init__(self):
        super(Ui_login_info_form, self).__init__()
        self.login_info_label = QtWidgets.QLabel()
    def setupUi(self, login_info_form):
        login_info_form.setObjectName("login_info_form")
        login_info_form.resize(400, 300)
        self.login_info_label = QtWidgets.QLabel(login_info_form)
        self.login_info_label.setGeometry(QtCore.QRect(90, 140, 211, 20))
        self.login_info_label.setAlignment(QtCore.Qt.AlignCenter)
        self.login_info_label.setObjectName("login_info_label")
        self.back_btn = QtWidgets.QPushButton(login_info_form)
        self.back_btn.setGeometry(QtCore.QRect(260, 220, 80, 20))
        self.back_btn.setObjectName("back_btn")

        self.retranslateUi(login_info_form)
        QtCore.QMetaObject.connectSlotsByName(login_info_form)

        '''
        signal & slot
        '''
        self.back_btn.clicked.connect(login_info_form.close)

    def retranslateUi(self, login_info_form):
        _translate = QtCore.QCoreApplication.translate
        login_info_form.setWindowTitle(_translate("login_info_form", "Form"))
        self.login_info_label.setText(_translate("login_info_form", "Login Succeed"))
        self.back_btn.setText(_translate("login_info_form", "back"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    login_info_form = QtWidgets.QWidget()
    ui = Ui_login_info_form()
    ui.setupUi(login_info_form)
    login_info_form.show()
    sys.exit(app.exec_())
