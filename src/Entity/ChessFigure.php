<?php

/*
 *@file
 * Contains \Drupal\chess\Entity\ChessFigure
 */


namespace Drupal\chess\Entity;

use Drupal\Core\Entity\EntityStorageInterface;
use Drupal\Core\Entity\EntityTypeInterface;
use Drupal\Core\Field\BaseFieldDefinition;
use Drupal\Core\Entity\ContentEntityBase;
use Drupal\chess\Entity\ChessFigureInterface;
use Drupal\Core\Entity\EntityChangedTrait;
use Drupal\user\UserInterface;

/*
* @ContentEntityType(
 *   id = "chess_chess_figure",
 *   label = @Translation("ChessFigure entity"),
 *   handlers = {
 *     "view_builder" = "Drupal\Core\Entity\EntityViewBuilder",
 *     "list_builder" = "Drupal\chess\Entity\Controller\ChessFigureListBuilder",
 *     "form" = {
 *       "add" = "Drupal\chess\Form\ChessFigureForm",
 *       "edit" = "Drupal\chess\Form\ChessFigureForm",
 *       "delete" = "Drupal\chess\Form\ChessFigureDeleteForm",
 *     },
 *     "access" = "Drupal\chess\ChessFigureAccessControlHandler",
 *   },
 *   list_cache_contexts = { "user" },
 *   base_table = "chess_figure",
 *   admin_permission = "administer chess",
 *   fieldable = FALSE,
 *   entity_keys = {
 *     "id" = "id",
 *     "label" = "type",
 *     "uuid" = "uuid"
 *   },
 *   links = {
 *     "canonical" = "/chess-figure/{chess_chess_figure}",
 *     "edit-form" = "/chess-figure/{chess_chess_figure}/edit",
 *     "delete-form" = "/chess-figure/{chess_chess_figure}/delete",
 *     "collection" = "/chess-figure/list"
 *   },
 *   field_ui_base_route = "chess.chess_figure_settings",
 * )
 */

class ChessFigure extends ContentEntityBase implements ChessFigureInterface {

  use EntityChangedTrait;

  public static function preCreate (EntityStorageInterface $storage_controller, array &$values){
    parent::preCreate($storage_controller,$values);
    $values += array(

    );
  }

  public function setCoordinate($x, $y) {
    $this->set('coordinate',$x . $y);
    return $this;
  }

  public function getCoordinate() {
    return $this->get('coordinate')->value;
  }

  public function setColor($color) {
    $this->set('color',$color);
    return $this;
  }

  public function getColor() {
    return $this->get('color')->value;
  }

  public function getType() {
    $this->get('type')->value;
  }

  public function setType($type) {
    $this->set('type',$type);
    return $this;
  }

  public function getCreatedTime() {
    return $this->get('created')->values;
  }

  public function getChangedTime() {
    return $this->get('changed')->value;
  }

  public function getOwner() {
    return $this->get('user_id')->entity;
  }

  public function getOwnerId() {
    return $this->get('user_id')->target_id;
  }

  public function setOwner(UserInterface $account) {
    $this->set('user_id', $account->id());
    return $this;
  }

  public function setOwnerId($uid) {
    $this->set('user_id', $uid);
    return $this;
  }

  /**
   * Provides base field definitions for an entity type.
   *
   * Implementations typically use the class
   * \Drupal\Core\Field\BaseFieldDefinition for creating the field definitions;
   * for example a 'name' field could be defined as the following:
   * @code
   * $fields['name'] = BaseFieldDefinition::create('string')
   *   ->setLabel(t('Name'));
   * @endcode
   *
   * By definition, base fields are fields that exist for every bundle. To
   * provide definitions for fields that should only exist on some bundles, use
   * \Drupal\Core\Entity\FieldableEntityInterface::bundleFieldDefinitions().
   *
   * The definitions returned by this function can be overridden for all
   * bundles by hook_entity_base_field_info_alter() or overridden on a
   * per-bundle basis via 'base_field_override' configuration entities.
   *
   * @param \Drupal\Core\Entity\EntityTypeInterface $entity_type
   *   The entity type definition. Useful when a single class is used for multiple,
   *   possibly dynamic entity types.
   *
   * @return \Drupal\Core\Field\FieldDefinitionInterface[]
   *   An array of base field definitions for the entity type, keyed by field
   *   name.
   *
   * @see \Drupal\Core\Entity\EntityManagerInterface::getFieldDefinitions()
   * @see \Drupal\Core\Entity\FieldableEntityInterface::bundleFieldDefinitions()
   */
  public static function baseFieldDefinitions(EntityTypeInterface $entity_type) {
    $fields['id'] = BaseFieldDefinition::create('integer')
      ->setLabel(t('id'))
      ->setDescription(t('The ID of the Chess Figure entity.'))
      ->setReadOnly(TRUE);

    $fields['uuid'] = BaseFieldDefinition::create('uuid')
      ->setLabel(t('UUID'))
      ->setDescription(t('The UUID of the Chess Figure entity.'))
      ->setReadOnly(TRUE);

    $fields['type'] = BaseFieldDefinition::create('list_string')
      ->setLabel(t('Type'))
      ->setDescription(t('The Type of the Chess Figure entity.'))
      ->setSettings(array(
        'allowed_values' => array(
          'pawn' => 'pawn',
          'castle' => 'castle',
          'knight' => 'knight',
          'bishop' => 'bishop',
          'queen' => 'queen',
          'king' => 'king'
        ),
      ))
      ->setDisplayOptions('view', array(
        'label' => 'above',
        'type' => 'string',
        'weight' => -4,
      ))
      ->setDisplayOptions('form', array(
        'type' => 'options_select',
        'weight' => -4,
      ))
      ->setDisplayConfigurable('form', TRUE)
      ->setDisplayConfigurable('view', TRUE);

    $fields['color'] = BaseFieldDefinition::create('list_string')
      ->setLabel(t('Color'))
      ->setDescription(t('The color of the Chess Figure entity.'))
      ->setSettings(array(
        'allowed_values' => array(
          'white' => 'white',
          'black' => 'black',
        ),
      ))
      ->setDisplayOptions('view', array(
        'label' => 'above',
        'type' => 'string',
        'weight' => -3,
      ))
      ->setDisplayOptions('form', array(
        'type' => 'options_select',
        'weight' => -3,
      ))
      ->setDisplayConfigurable('form', TRUE)
      ->setDisplayConfigurable('view', TRUE);

    $fields['coordinate'] = BaseFieldDefinition::create('string')
      ->setLabel(t('Coordinate'))
      ->setDescription(t('The coordinate of the Chess Figure entity.'))
      ->setSettings(array(
        'default_value' => '',
        'max_length' => 255,
        'text_processing' => 0,
      ))
      ->setDisplayOptions('view', array(
        'label' => 'above',
        'type' => 'string',
        'weight' => -5,
      ))
      ->setDisplayOptions('form', array(
        'type' => 'string',
        'weight' => -5,
      ))
      ->setDisplayConfigurable('form', TRUE)
      ->setDisplayConfigurable('view', TRUE);


    $fields['langcode'] = BaseFieldDefinition::create('language')
      ->setLabel(t('Language code'))
      ->setDescription(t('The language code of Chess Figure entity.'));

    $fields['created'] = BaseFieldDefinition::create('created')
      ->setLabel(t('Created'))
      ->setDescription(t('The time that the entity was created.'));

    $fields['changed'] = BaseFieldDefinition::create('changed')
      ->setLabel(t('Changed'))
      ->setDescription(t('The time that the entity was last edited.'));

    return $fields;
  }
}
