<?php
class ChessFigureMetadataController extends EntityDefaultMetadataController{
  public function entityPropertyInfo(){
    $info = parent::entityPropertyInfo();

    $properties = &$info[$this->type]['properties'];

    $properties['created'] = array(
      'label' => t('Date created'),
      'type' => 'date',
      'description' => t('The date the figure was created.'),
      'setter callback' => 'entity_property_verbatim_set',
      'schema field' => 'created',
    );
    $properties['changed'] = array(
      'label' => t('Date changed'),
      'type' => 'date',
      'description' => t('The date the figure was changed.'),
      'schema field' => 'changed',
    );

    return $properties;

  }
}
