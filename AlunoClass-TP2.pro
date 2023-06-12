QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aluno.cpp \
    alunocontroler.cpp \
    alunodao.cpp \
    disciplina.cpp \
    disciplinacontroler.cpp \
    disciplinadao.cpp \
    main.cpp \
    mainwindow.cpp \
    matricula.cpp \
    matriculadao.cpp \
    turma.cpp \
    turmacontroler.cpp \
    turmadao.cpp

HEADERS += \
    aluno.h \
    alunocontroler.h \
    alunodao.h \
    dao.h \
    disciplina.h \
    disciplinacontroler.h \
    disciplinadao.h \
    mainwindow.h \
    matricula.h \
    matriculadao.h \
    turma.h \
    turmacontroler.h \
    turmadao.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
