# -*- coding: utf-8 -*-
from PySide2 import QtCore, QtGui, QtWidgets
from PySide2.QtWidgets import *
from login_confirm import *


class Ui_login_form(QtWidgets.QWidget):
    def setupUi(self, login_form):
        login_form.setObjectName("login_form")
        login_form.resize(400, 300)
        self.name_label = QtWidgets.QLabel(login_form)
        self.name_label.setGeometry(QtCore.QRect(80, 100, 60, 20))
        self.name_label.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.name_label.setObjectName("name_label")
        self.password_label = QtWidgets.QLabel(login_form)
        self.password_label.setGeometry(QtCore.QRect(80, 150, 60, 20))
        self.password_label.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.password_label.setObjectName("password_label")
        self.name_lineedit = QtWidgets.QLineEdit(login_form)
        self.name_lineedit.setGeometry(QtCore.QRect(150, 100, 150, 20))
        self.name_lineedit.setMaxLength(15)
        self.name_lineedit.setEchoMode(QtWidgets.QLineEdit.Normal)
        self.name_lineedit.setObjectName("name_lineedit")
        self.password_lineedit = QtWidgets.QLineEdit(login_form)
        self.password_lineedit.setGeometry(QtCore.QRect(150, 150, 150, 20))
        self.password_lineedit.setMaxLength(15)
        self.password_lineedit.setEchoMode(QtWidgets.QLineEdit.Password)
        self.password_lineedit.setObjectName("password_lineedit")
        self.ok_btn = QtWidgets.QPushButton(login_form)
        self.ok_btn.setGeometry(QtCore.QRect(220, 200, 80, 20))
        self.ok_btn.setObjectName("ok_btn")

        self.retranslateUi(login_form)
        QtCore.QMetaObject.connectSlotsByName(login_form)

        '''
        signal&slot
        '''
        self.ok_btn.clicked.connect(self.login_ok)

    def retranslateUi(self, login_form):
        _translate = QtCore.QCoreApplication.translate
        login_form.setWindowTitle(_translate("login_form", "login"))
        self.name_label.setText(_translate("login_form", "name:"))
        self.password_label.setText(_translate("login_form", "password:"))
        self.ok_btn.setText(_translate("login_form", "Ok"))

    def login_ok(self):
        if self.name_lineedit.text() == '':
            ret = QMessageBox.about(self, 'Tips', 'Please input your name!')
        else:
            if self.password_lineedit.text() == '':
                ret = QMessageBox.about(self, 'Tips', 'Please input your passwords!')
            else:
                login_info = Ui_login_info_form()
                self.window = QWidget()
                login_info.setupUi(self.window)
                self.window.show()


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    login_form = QtWidgets.QWidget()
    ui = Ui_login_form()
    ui.setupUi(login_form)
    login_form.show()
    sys.exit(app.exec_())
