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
    $properties['type'] = array(
        'type' => 'varchar',
        'getter callback' => 'entity_property_getter_method',
        'setter callback' => 'entity_property_verbatim_set',
        'required' => TRUE,
        'description' => t('The chess figure type.'),
      ) + $properties['type'];

    $properties['changed'] = array(
      'label' => t("Date changed"),
      'type' => 'date',
      'schema field' => 'changed',
      'description' => t("The date the figure was most recently updated."),
    );
    $properties['cell_x'] = array(
      'label' => t("x"),
      'type' => 'int',
      'schema field' => 'cell',
      'description' => t("The cell x the figure was most recently updated."),
    );
    $properties['color'] = array(
      'label' => t("color"),
      'type' => 'varchar',
      'schema field' => 'color',
      'description' => t("The color of figure ."),
    );
    $properties['cell_y'] = array(
      'label' => t("y"),
      'type' => 'int',
      'schema field' => 'cell',
      'description' => t("The cell y the figure was most recently updated."),
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