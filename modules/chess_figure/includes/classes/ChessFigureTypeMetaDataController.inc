<?php
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
