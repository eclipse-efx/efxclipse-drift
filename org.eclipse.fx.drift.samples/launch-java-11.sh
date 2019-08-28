#!/bin/sh

/Users/tomschindl/Applications/java-tools/jdk-11.jdk/Contents/Home/bin/java \
 -Djava.library.path=/Users/tomschindl/git/efxclipse-drift/org.eclipse.fx.drift.samples/native:/Users/tomschindl/git/efxclipse-drift/org.eclipse.fx.drift/native \
 -Dfile.encoding=UTF-8 \
 -classpath /Users/tomschindl/git/efxclipse-drift/org.eclipse.fx.drift/target/classes:/Users/tomschindl/git/efxclipse-drift/org.eclipse.fx.drift.samples/target/classes:/Users/tomschindl/.m2/repository/at/bestsolution/efxclipse/rt/org.eclipse.fx.core/3.4.1.201809241052/org.eclipse.fx.core-3.4.1.201809241052.jar:/Users/tomschindl/.m2/repository/at/bestsolution/efxclipse/eclipse/com.google.guava/21.0.0.v20170206-1425/com.google.guava-21.0.0.v20170206-1425.jar:/Users/tomschindl/.m2/repository/at/bestsolution/efxclipse/eclipse/javax.inject/1.0.0.v20091030/javax.inject-1.0.0.v20091030.jar:/Users/tomschindl/.m2/repository/at/bestsolution/efxclipse/eclipse/org.apache.commons.lang/2.6.0.v201404270220/org.apache.commons.lang-2.6.0.v201404270220.jar \
 --module-path /Users/tomschindl/Downloads/javafx-sdk-11.0.2/lib \
 --add-modules javafx.controls \
 --add-exports javafx.graphics/com.sun.javafx.sg.prism=ALL-UNNAMED \
 --add-exports javafx.graphics/com.sun.javafx.scene=ALL-UNNAMED \
 --add-exports javafx.graphics/com.sun.javafx.util=ALL-UNNAMED \
 --add-exports javafx.graphics/com.sun.javafx.tk=ALL-UNNAMED \
 --add-exports javafx.graphics/com.sun.javafx.geom=ALL-UNNAMED \
 --add-exports javafx.graphics/com.sun.javafx.geom.transform=ALL-UNNAMED \
 --add-opens javafx.graphics/com.sun.prism=ALL-UNNAMED \
 --add-opens javafx.graphics/com.sun.prism.es2=ALL-UNNAMED \
 --add-opens javafx.graphics/com.sun.prism.impl=ALL-UNNAMED \
 org.eclipse.fx.drift.samples.Demo 