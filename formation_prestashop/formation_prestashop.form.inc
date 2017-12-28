<?php

function formation_prestashop_form($form, &$form_state){
  $form['title'] = array(
    '#title' => t('Nom du partenaire'),
    '#type' => 'textfield',
    '#default_value' => '',
    '#required' => TRUE,
  );
  $form['couleur'] = array(
        '#title' => t('Couleur'),
        '#type' => 'select',
        '#required' => TRUE,
        '#options' => get_taxonomy_color_list(),
    );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Envoyer le formulaire'),
    '#weight' => 50,
  );
  return $form;
}

function get_taxonomy_color_list(){
  $results = db_query("SELECT tid, name FROM {taxonomy_term_data} WHERE vid = 3")->fetchAll();
  $options = array();
  foreach($results  as $key=>$value){
    $options[$key] = $value->name;
  }
 return $options;
}

function formation_prestashop_form_validate($form, &$form_state){

}

function formation_prestashop_form_submit($form, &$form_state){
  drupal_set_message(t('Le formulaire avec pour titre @title.', array('@title' => $form_state['values']['title'])));
  $form_state['redirect'] = 'prest/test/form';
}
