package org.eclipse.fx.drift.tooling;

import com.google.common.base.Objects;
import java.util.List;
import org.eclipse.fx.drift.tooling.Feature;
import org.eclipse.fx.drift.tooling.Remove;
import org.eclipse.fx.drift.tooling.Require;
import org.eclipse.xtext.xbase.lib.CollectionLiterals;
import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

@SuppressWarnings("all")
public class FeatureHandler extends DefaultHandler {
  public List<Feature> features = CollectionLiterals.<Feature>newArrayList();
  
  private Feature curFeature = null;
  
  private Require curRequire = null;
  
  private Remove curRemove = null;
  
  public void startElement(final String uri, final String localName, final String qName, final Attributes attributes) throws SAXException {
    boolean _matched = false;
    if (Objects.equal(qName, "feature")) {
      _matched=true;
      Feature _feature = new Feature();
      this.curFeature = _feature;
      this.curFeature.api = attributes.getValue("api");
      this.curFeature.name = attributes.getValue("name");
      this.curFeature.number = attributes.getValue("number");
    }
    if (!_matched) {
      if (Objects.equal(qName, "require")) {
        _matched=true;
        if ((this.curFeature != null)) {
          Require _require = new Require();
          this.curRequire = _require;
          this.curRequire.comment = attributes.getValue("comment");
        }
      }
    }
    if (!_matched) {
      if (Objects.equal(qName, "remove")) {
        _matched=true;
        Remove _remove = new Remove();
        this.curRemove = _remove;
        this.curRemove.profile = attributes.getValue("profile");
        this.curRemove.comment = attributes.getValue("comment");
      }
    }
    if (!_matched) {
      if (Objects.equal(qName, "type")) {
        _matched=true;
        if ((this.curRequire != null)) {
          this.curRequire.types.add(attributes.getValue("name"));
        } else {
          if ((this.curRemove != null)) {
            this.curRemove.types.add(attributes.getValue("name"));
          }
        }
      }
    }
    if (!_matched) {
      if (Objects.equal(qName, "enum")) {
        _matched=true;
        if ((this.curRequire != null)) {
          this.curRequire.enums.add(attributes.getValue("name"));
        } else {
          if ((this.curRemove != null)) {
            this.curRemove.enums.add(attributes.getValue("name"));
          }
        }
      }
    }
    if (!_matched) {
      if (Objects.equal(qName, "command")) {
        _matched=true;
        if ((this.curRequire != null)) {
          this.curRequire.commands.add(attributes.getValue("name"));
        } else {
          if ((this.curRemove != null)) {
            this.curRemove.commands.add(attributes.getValue("name"));
          }
        }
      }
    }
  }
  
  public void endElement(final String uri, final String localName, final String qName) throws SAXException {
    boolean _matched = false;
    if (Objects.equal(qName, "feature")) {
      _matched=true;
      this.features.add(this.curFeature);
      this.curFeature = null;
    }
    if (!_matched) {
      if (Objects.equal(qName, "require")) {
        _matched=true;
        if ((this.curFeature != null)) {
          this.curFeature.requires.add(this.curRequire);
          this.curRequire = null;
        }
      }
    }
    if (!_matched) {
      if (Objects.equal(qName, "remove")) {
        _matched=true;
        this.curFeature.removes.add(this.curRemove);
        this.curRemove = null;
      }
    }
  }
}
