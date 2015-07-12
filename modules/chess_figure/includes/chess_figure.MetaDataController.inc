<?php
class ChessFigureMetaDataController extends EntityDefaultMetadataController{
  public function entityPropertyInfo(){
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];
    $properties['created'] = array(
      'label' => t("Date created"),
      'type' => 'date',
      'description' => t("The date the figure was created."),
      'setter callback' => 'entity_property_verbatim_set',
      'schema field' => 'created',
    );

    $properties['changed'] = array(
      'label' => t("Date changed"),
      'type' => 'date',
      'schema field' => 'changed',
      'description' => t("The date the figure was most recently updated."),
    );


return $properties;

  }
}
class ChessFigureTypeMetaDataController extends EntityDefaultMetadataController{
  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];
    $properties['description'] = array(
      'label' => t("Description"),
      'type' => 'varchar',
      'schema field' => 'description',
      'description' => t("The description of chess figure."),
    );
    return $properties;
  }
}