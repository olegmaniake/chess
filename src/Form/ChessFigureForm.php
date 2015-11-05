<?php

namespace Drupal\chess\Form;

use Drupal\Core\Entity\ContentEntityForm;
use Drupal\Core\Language\Language;
use Drupal\Core\Form\FormStateInterface;

class ChessFigureForm extends ContentEntityForm {
  public function buildForm(array $form, FormStateInterface $form_state){
    /*
     * @var $entity \Drupal\chess\Entity\ChessFigure
     */

    $form = parent::buildForm($form,$form_state);
    $entity = $this->entity;

    $form['langcode'] = array(
      '#title' => $this->t('Language'),
      '#type' => 'language_select',
      '#default_value' => $entity->getUntranslated()->languege()->getId(),
      '#language' => language::STATE_ALL,
    );

    return $form;
  }

  public function save(array $form, FormStateInterface $form_state) {
    $form_state->setRedirect('entity.chess_chess_figure.collection');
    $entity = $this->getEntity();
    $entity->save();
  }
}
