package org.eclipse.fx.drift.tooling;

import java.util.List;
import org.eclipse.fx.drift.tooling.Remove;
import org.eclipse.fx.drift.tooling.Require;
import org.eclipse.xtext.xbase.lib.CollectionLiterals;

@SuppressWarnings("all")
public class Feature {
  public String api;
  
  public String name;
  
  public String number;
  
  public List<Require> requires = CollectionLiterals.<Require>newArrayList();
  
  public List<Remove> removes = CollectionLiterals.<Remove>newArrayList();
}
